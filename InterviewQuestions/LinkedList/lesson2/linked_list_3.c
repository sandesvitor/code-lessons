#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


void push(Node* head, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_node;
}

void print_list(Node* head){
    while(head != NULL){
        printf("%d->", head->data);
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

// O(4n) => O(n)
void add_to_number_from_list(Node* head){
    int number_from_list = 0;
    int number_for_list = 0;
    int base_ten_counter = 1;
    reverse_list(&head);
    Node* tmp = head;

    while(tmp != NULL){
        number_from_list += tmp->data * base_ten_counter;
        base_ten_counter *= 10;
        tmp = tmp->next;     
    } 
    reverse_list(&head);

    number_from_list++;
    base_ten_counter /= 10;   

    while(head != NULL){
        number_for_list = (number_from_list / base_ten_counter) % 10;
        head->data = number_for_list;
        base_ten_counter /= 10;
        head = head->next;
    }    
}

int main(){
    /*
        If 1 is added to list, change all values such as a normal sum:
        Ex: List: 1 -> 9 -> 9-> 9 -> NULL (+1) = 2 -> 0 -> 0 -> 0;
    */
    Node* HEAD = (Node*)malloc(sizeof(Node));
    HEAD->data = 1;
    HEAD->next = NULL;
    
    push(HEAD, 9);
    push(HEAD, 9);
    push(HEAD, 9);
    print_list(HEAD);

    add_to_number_from_list(HEAD);
    print_list(HEAD);

    return 0;
}
