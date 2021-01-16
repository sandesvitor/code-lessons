#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


void push(Node* head, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_node;
}

void print_list(Node* head){
    while(head != NULL){
        printf("%d(%p)->", head->data, (void*)(head));
        head = head->next;
    }
    printf("\n");
}

void reverse_list(Node* head);

void delete_nth_node(Node* head, int n){
    Node* tmp = head;
    Node* prev = NULL;
    int i = 1;
    while(tmp != NULL){
        if(i == n){
            break;
        }
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
    if(tmp == NULL)
        return;

    prev->next = tmp->next;
    tmp = NULL;
    free(tmp);
}

void delete_middle_node(Node* head){
    Node* tmp = head;
    Node* fast_pointer = head;
    Node* slow_pointer = head;
    Node* prev = NULL;
    int list_length = 1;
    while(tmp->next != NULL){
        list_length++;
        tmp = tmp->next;
    }
    while(fast_pointer != NULL && fast_pointer->next != NULL){
        prev = slow_pointer;
        fast_pointer = (fast_pointer->next)->next;
        slow_pointer = slow_pointer->next;
    }
    prev->next = slow_pointer->next;
    slow_pointer = NULL;
    free(slow_pointer);
    fast_pointer = NULL;    
    free(fast_pointer);
}

int main(){
    
    Node* HEAD = (Node*)malloc(sizeof(Node));
    HEAD->data = 1;
    HEAD->next = NULL;

    push(HEAD, 34);
    push(HEAD, 56);
    push(HEAD, 78);

    printf("\nTEST 1:\n");
    print_list(HEAD);

    push(HEAD, 669);
    
    printf("\nTEST 2:\n");
    print_list(HEAD);

    /*
    printf("\nTEST 3:\n");
    delete_nth_node(HEAD, 3);
    print_list(HEAD);
    */

    printf("\nTEST 4:\n");
    delete_middle_node(HEAD);
    print_list(HEAD);

    return 0;
}
