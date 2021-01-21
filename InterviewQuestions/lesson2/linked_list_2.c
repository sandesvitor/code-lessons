#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    char data;
    struct Node* next;
}Node;


void push(Node* head, char data){
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
        printf("%c(%p)->", head->data, (void*)(head));
            head = head->next;
    }
    printf("\n");
}

void reverse_list(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        
        prev = current;
        current = next;
    }
    *head = prev;
}

bool is_palindrome(Node* head){
    Node* reversed_head = head;
    reverse_list(&reversed_head);
    while(head != NULL){
        if(reversed_head->data != head->data){
            return 0;
        }
        reversed_head = reversed_head->next;
        head = head->next;
    }
    return 1;
}




int main(){
    Node* HEAD = (Node*)malloc(sizeof(Node));
    HEAD->data = 'R';
    HEAD->next = NULL;
    
    push(HEAD, 'A');
    push(HEAD, 'D');
    push(HEAD, 'A');
    push(HEAD, 'R');
    push(HEAD, 'Z');
    
    print_list(HEAD);
    printf("Is Palindrome: %d", is_palindrome(HEAD)); 
    return 0;
}
