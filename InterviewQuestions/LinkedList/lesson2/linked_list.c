#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


// O(n)
void push(Node* head, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new_node;
}

// O(n)
void print_list(Node* head){
    while(head != NULL){
        printf("%d(%p)->", head->data, (void*)(head));
        head = head->next;
    }
    printf("\n");
}

// O(2n) ==> O(n)
void reverse_list(Node* head);

// O(2n) ==> O(n)
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

// O(2n) ==> O(n)
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

// O(n)
void remove_duplicate_data(Node* head){
    Node* tmp = NULL;
    Node* prev = NULL;
    while(head->next != NULL){
        prev = head;
        tmp = head->next;
        if( ( (head->data) - ((head->next)->data) ) == 0 ){
            prev->next = tmp->next;
            tmp->next = NULL;
        } else {
            head = head->next;
        }
    }
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



    // New list:
    Node* NEW_HEAD = (Node*)malloc(sizeof(Node));
    NEW_HEAD->data = 2;
    NEW_HEAD->next = NULL;
    push(NEW_HEAD, 3);
    push(NEW_HEAD, 3);
    // push(NEW_HEAD, 3);
    push(NEW_HEAD, 5);
    printf("\nNew List:\n");
    print_list(NEW_HEAD);

    printf("\nTEST 5:\n");
    remove_duplicate_data(NEW_HEAD);
    print_list(NEW_HEAD);
        


    return 0;
}
