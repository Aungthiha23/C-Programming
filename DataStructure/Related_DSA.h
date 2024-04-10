//
// Created by USER on 15/03/2024.
//

#ifndef DATA_STRUCTURE_WITH_C_RELATED_DSA_H
#define DATA_STRUCTURE_WITH_C_RELATED_DSA_H
#include "stdio.h"
#include "stdlib.h"
#define MAX_SIZE 30

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
//for Stack data structure using array
struct Stack_A {
    int top;
    int data[MAX_SIZE];
};
//for Stack data Structure using linked list
struct SL_node{
    int data;
    struct SL_node* next;
};
struct Stack_LL{
    struct SL_node* top;
};
//for Queue data structure using linked list
struct Q_node{
    int data;
    struct Q_node* next;
};
struct QueueLL{
    struct Q_node* q_front;
    struct Q_node* q_back;
};
//for Tree data structure
struct Tree_Node{
    int data;
    struct Tree_Node* left;
    struct Tree_Node* right;
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

// -> Stack Data Structure using Array<- //

void SA_initialize(struct Stack_A *stack){
    stack->top=-1;

}

int SA_isFull(struct Stack_A* stack){
    return (stack->top==MAX_SIZE-1);
}


int SA_isEmpty(struct Stack_A* stack){
    return stack->top == -1;
}


void SA_push(struct Stack_A* stack, int value){
    if(SA_isFull(stack)){
        printf("Stack is full \n");
        exit(3);
    }else{
        stack->data[++stack->top] = value;
        printf("Value inserted index -> %d = value -> %d \n",stack->top,stack->data[stack->top]);
    }

}

int SA_pop(struct Stack_A* stack){
    if (SA_isEmpty(stack)){
        printf("Underflow \n");
        exit(3);
    }

    return stack->data[stack->top--];
}

int SA_peek(struct Stack_A* stack){
    if (SA_isEmpty(stack)){
        printf("NO Data \n");
    }

    return stack->data[stack->top];
}

void SA_display(struct Stack_A* stack) {
    if (SA_isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = stack->top; i >= 0; i--) {
            printf("Elements in the stack at %d : %d \n",i, stack->data[i]);
        }
        printf("\n");
    }
}

// -> Stack Data Structure using Array <- //

// -> Stack Data Structure using Linked list <- //
void SL_initializeStack(struct Stack_LL* stack){
    stack->top=NULL;
}
int SL_isEmpty(struct Stack_LL* stack){
    return (stack->top==NULL);
}
void SL_push(struct Stack_LL* stack,int data){
    struct SL_node* newNode=(struct SL_node*) malloc(sizeof (struct SL_node));
    if(newNode == NULL){
        printf("Memory Allocation failed \n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=stack->top;
    stack->top=newNode;
    printf("New Node Pushed \n");
}
int SL_pop(struct Stack_LL* stack){
    if(SL_isEmpty(stack)){
        printf("Stack underflow \n");
        exit(1);
    }else{
        struct SL_node* temp=stack->top;
        int data=temp->data;
        stack->top=temp->next;
        free(temp);
        return data;
    }
}
int SL_peep( struct Stack_LL* stack){
    if(SL_isEmpty(stack)){
        printf("Stack underflow \n");
        exit(1);
    }
    return stack->top->data;
}
// -> Stack Data Structure using Linked list <- //
// -> Queue Data Structure using Array <- //
int Queue[MAX_SIZE];
int Q_front=-1;
int Q_back=-1;
int Q_isFull(){
    if(Q_back==MAX_SIZE-1){
        return 1;
    }else return 0;
}
int Q_isEmpty(){
    if(Q_front==-1){
        return 1;
    }else return 0;
}
void Enqueue(int data){
    if(Q_isFull()){
        printf("Queue is full");
    }else{
        if(Q_front==-1) Q_front=0;
        Q_back++;
        Queue[Q_back]=data;
        printf("Adding data queue is successful");
    }
}
// add data to queue with another way 
// first data index is 0,second data index is 0 and first data index move to 1
void Another_enqueue(int data){
    if(Q_isFull()){
        printf("Queue is full");
    }else{
        if(Q_isEmpty())Q_front=0;
        Q_back++;
        for (int i = Q_back; i >Q_front ; i--) {
            Queue[i] =Queue[i-1];
        }
        Queue[Q_front]=data;
    }
}
int Dequeue(){
    int data=-1;
    if(Q_isEmpty()){
        printf("No data in queue");
    }else{
        data=Queue[Q_front];
        Q_front++;
        if(Q_front>Q_back) Q_front=Q_back=-1;
    }
    return data;
}
void display(){
    if(Q_back==-1){
        printf("Queue is empty");
    }else{
        for(int i=Q_front;i<=Q_back;i++){
            printf("%d ",Queue[i]);
        }
        printf("\n");
    }
}
// -> Queue Data Structure using Array <- //
// -> Queue Data Structure using Linked list <- //
int QLL_isEmpty(struct QueueLL* queue){
    return (queue->q_front==NULL);
}
struct QueueLL* createQueue(){
    struct QueueLL* queue=(struct QueueLL*) malloc(sizeof (struct QueueLL));
    if(queue==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    queue->q_front=queue->q_back=NULL;
    return queue;
}
void LL_enqueue(struct QueueLL* queue,int data){
    struct Q_node* newNode=(struct Q_node*) malloc(sizeof (struct Q_node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    if(QLL_isEmpty(queue)){
        queue->q_front=queue->q_back=newNode;
    } else{
        queue->q_back->next=newNode;
        queue->q_back=newNode;
    }
}
int LL_dequeue(struct QueueLL* queue){
    if(QLL_isEmpty(queue)){
        printf("queue is empty .\n");
        exit(1);
    }
    struct Q_node* QNode=queue->q_front;
    int data=QNode->data;
    queue->q_front=queue->q_front->next;
    free(QNode);
    return data;
}
void QLL_display(struct QueueLL* queue){
    if(QLL_isEmpty(queue)){
        printf("no data in queue \n");
        exit(1);
    }
    struct Q_node* temp_Node=queue->q_front;
    while (temp_Node!=NULL){
        printf("queue element are %d :",temp_Node->data);
       temp_Node =temp_Node->next;
    }
}
// -> Queue Data Structure using Linked List <- //
// -> Tree Data Structure <- //
struct Tree_Node* createNode(int data){
    struct Tree_Node* newNode=(struct Tree_Node*) malloc(sizeof (struct Tree_Node));
    if(newNode==NULL){
        printf("Memory allocation fail");
        exit(1);
    }
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Tree_Node* Find_Min(struct Tree_Node* root){
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct Tree_Node* insert_Node(struct Tree_Node* root,int data){
    if(root == NULL){
        root=createNode(data);
    }else if(data<root->data){
        root->left= insert_Node(root->left,data);
    } else{
        root->right= insert_Node(root->right,data);
    }
    return root;
}
struct Tree_Node* dalete_Node(struct Tree_Node* root,int data){
    if(root==NULL){
        return root;
    }else if(data<root->data){
        root->left= dalete_Node(root->left,data);
    }else if(data>root->data){
        root->right= dalete_Node(root->right,data);
    }else{
        if(root->left==NULL){
            struct Tree_Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct Tree_Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Tree_Node* temp= Find_Min(root->right);
        root->data=temp->data;
        root->right= dalete_Node(root->right,temp->data);
    }
    return root;
}
// -> Tree Data Structure <- //

#endif //DATA_STRUCTURE_WITH_C_RELATED_DSA_H
