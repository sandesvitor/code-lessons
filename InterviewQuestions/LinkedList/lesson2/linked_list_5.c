#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;


void push(Node* head, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_node;
    new_node->prev = head;
}

void print_forward(Node* head){
    while(head->next != NULL){
        printf("%d(%p)->", head->data, (void*)(head));
        head = head->next;
    }
    printf("\n");
    print_backward(head);
}

void print_backward(Node* head){
    while(head != NULL){
        printf("%d(%p)->", head->data, (void*)(head));
        head = head->prev;
    }
    printf("\n");
}

void merge_list_alternate(Node* head_list_1, Node* head_list_2){
    Node* prev_1 = NULL;
    Node* prev_2 = NULL;
    while(head_list_2->next != NULL){
        prev_1 = head_list_1;
        prev_2 = head_list_2;
        prev_1->next = head_list_2;
        prev_2->next = head_list_1;
        
        head_list_1 = head_list_1->next;
        head_list_2 = head_list_2->next;
        
    }
}


int main(){
    Node* HEAD_A = (Node*)malloc(sizeof(Node));
    HEAD_A->data = 5;
    HEAD_A->next = NULL;

    Node* HEAD_B = (Node*)malloc(sizeof(Node));
    HEAD_B->data = 12;
    HEAD_B->next = NULL;

    // pushing to list A:
    push(HEAD_A, 7);
    push(HEAD_A, 17);
    push(HEAD_A, 13);
    push(HEAD_A, 11);
    print(HEAD_A);
    
    // pushing to list B:
    push(HEAD_B, 10);
    push(HEAD_B, 2);
    push(HEAD_B, 4);
    push(HEAD_B, 6);
    print(HEAD_B);

    // merging:
    //merge_list_alternate(HEAD_A, HEAD_B);
   // print(HEAD_A);

    return 0;
}
