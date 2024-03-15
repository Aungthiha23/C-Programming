//
// Created by USER on 15/03/2024.
//

#ifndef DATA_STRUCTURE_WITH_C_RELATED_DSA_H
#define DATA_STRUCTURE_WITH_C_RELATED_DSA_H
#include "stdio.h"
#include "stdlib.h"
#define MAX_SIZE 20

// for single linked list  structure
struct S_node{
    int data;
    struct S_node *next;
};
// for double linked list structure
struct D_node{
    int data;
    struct D_node* next;
    struct D_node* prev;
};
//for Stack data structure
struct Stack {
    int top;
    int data[MAX_SIZE];

};
// -> singly linked list <-//

struct S_node* S_createNode(int new_Data){
    struct S_node* new_Node=(struct S_node*)malloc(sizeof (struct S_node));
    new_Node->data=new_Data;
    new_Node->next=NULL;

    return new_Node;
}

void S_insertAtBeginning(struct S_node** head,int new_Data){
    struct S_node* new_Node= S_createNode(new_Data);
    new_Node->next=*head;
    *head=new_Node;

}

void S_deleteNode(struct S_node** head,int key){
    struct S_node* temp=*head,*prev=NULL;

    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data != key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    prev->next=temp->next;
    free(temp);
}

void S_showData(struct S_node* node){

    while(node!=NULL){
        printf(" data : %d \n",node->data);
        node= node->next;
    }
}

// -> singly linked list <- //

// -> double linked list <- //

struct D_node* D_createNode(int newData){

    struct D_node* newNode=(struct D_node*) malloc(sizeof(struct D_node*));
    newNode->data =newData;
    newNode->next =NULL;
    newNode->prev =NULL;

    return newNode;
}

void D_insertAtBegining(struct D_node** head,int newdata){

    struct D_node* newNode=D_createNode(newdata);
    newNode->next=*head;
    if(*head != NULL){
        (*head)->prev=newNode;
    }
    *head = newNode;
}


void D_appendNode(struct D_node** head,int newdata){

    struct D_node* newNode=D_createNode(newdata);
    struct D_node* last=*head;
    if(*head ==NULL){
        *head =newNode;
        return;
    }

    while(last->next != NULL){
        last=last->next;
    }

    last->next=newNode;
    newNode->prev=last;

}
void D_deleteNode(struct D_node** head, int newdata) {

    struct D_node* deleteNode = *head, *prev_node = NULL;


    if (deleteNode != NULL && deleteNode->data == newdata) {
        if (deleteNode->next != NULL) {
            *head = deleteNode->next;
            (*head)->prev = NULL;
        } else {
            *head = NULL;
        }
        free(deleteNode);
        return;
    }


    while (deleteNode != NULL && deleteNode->data != newdata) {
        prev_node = deleteNode;
        deleteNode = deleteNode->next;
    }


    if (deleteNode == NULL) {
        printf("Node with data %d not found in the list.\n", deleteNode);
        return;
    }


    prev_node->next = deleteNode->next;
    if (deleteNode->next != NULL) {
        deleteNode->next->prev = prev_node;
    }


    free(deleteNode);
}

void D_displayBackward(struct D_node* head) {
    struct D_node* last = NULL;
    printf("Nodes in backward order: ");
    while (head != NULL) {
        last = head;
        head= head->next;
    }
    while (last != NULL) {
        printf(" data :%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
void D_deleteAtEnd(struct D_node** head) {
    if((*head) == NULL) return ;

    struct D_node* curr = *head;
    struct D_node* prev = curr->prev;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    prev->next = NULL;
    curr->prev = NULL;

    free(curr);
}

void D_alldata(struct D_node* Node){
    if(Node==NULL){
        return;
    }
    while(Node !=NULL){
        printf("data are  : %d \n",Node->data);
        Node=Node->next;
    }
}
// -> double linked list <- //

// -> Stack Data Structure <- //

void initialize(struct Stack *stack){
    stack->top=-1;

}

int isFull(struct Stack* stack){
    return (stack->top==MAX_SIZE-1);
}


int isEmpty(struct Stack* stack){
    return stack->top == -1;
}


void push(struct Stack* stack, int value){
    if(isFull(stack)){
        printf("Stack is full \n");
        exit(3);
    }else{
        stack->data[++stack->top] = value;
        printf("Value inserted index -> %d = value -> %d \n",stack->top,stack->data[stack->top]);
    }

}

int pop(struct Stack* stack){
    if (isEmpty(stack)){
        printf("Underflow \n");
        exit(3);
    }

    return stack->data[stack->top--];
}

int peek(struct Stack* stack){
    if (isEmpty(stack)){
        printf("NO Data \n");
    }

    return stack->data[stack->top];
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = stack->top; i >= 0; i--) {
            printf("Elements in the stack at %d : %d \n",i, stack->data[i]);
        }
        printf("\n");
    }
}

// -> Stack Data Structure <- //

#endif //DATA_STRUCTURE_WITH_C_RELATED_DSA_H
