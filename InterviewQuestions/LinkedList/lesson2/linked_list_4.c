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

void delete_list(Node** head){
    Node* prev = NULL;
    while(*head != NULL){
        prev = *head;
        *head = (*head)->next;
        free(prev);
    }
    printf("HEAP cleared!\n");
}


// O(3n) ==> O(n)
void rotate_list_data_k_times_counterclock(Node* head, int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    Node* tmp1 = head;
    Node* tmp2 = head;
    
    int list_length = 1;
    while(tmp1->next != NULL){
        list_length++;
        tmp1 = tmp1->next;
    }
    
    int stack[list_length];
    int i = 0;
    while(tmp2 != NULL){
        stack[i] = tmp2->data;
        tmp2 = tmp2->next;
        i++;
    }
    
    int new_index;    
    i = 0;
    while(head != NULL){
        new_index = i + k;
        if(new_index <= list_length - 1){
            head->data = stack[new_index];
        } else {
            head->data = stack[(-1) * (list_length - (i + k))];
        }
        head = head->next;
        i++;
    }
}

// O(n)
void rotate_list_nodes_k_times_counterclock(Node** head, int k){
    Node* curr = *head;
    Node* prev = NULL;
    Node* kth_node = NULL;
    int i = 0;
    while(curr->next != NULL){
        if(i < k){
            prev = curr;
            curr = curr->next;
            kth_node = curr;
        } else {
            curr = curr->next;
        }
        i++;
    }
    prev->next = NULL;
    curr->next = *head;
    *head = kth_node;
}

int main(){
    Node* HEAD = (Node*)malloc(sizeof(Node));
    HEAD->data = 1;
    HEAD->next = NULL;

    push(HEAD, 2);
    push(HEAD, 3);
    push(HEAD, 4);

    print_list(HEAD);
    
    // delete_list(&HEAD);
    // print_list(HEAD);

    //rotate_list_data_k_times_counterclock(HEAD, 3);
    //print_list(HEAD);

    rotate_list_nodes_k_times_counterclock(&HEAD, 3);
    print_list(HEAD);
    
    delete_list(&HEAD);

    return 0;
}
