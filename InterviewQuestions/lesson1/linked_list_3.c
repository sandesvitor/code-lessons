#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;


Node* createLinkedList(int n){
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;

    for(int i = 0; i < n; i++){

        // individual isolated node, not in the L.L.
        temp = (Node*)malloc(sizeof(Node));
        printf("\nEnter the data for node number %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if(head == NULL){ // if list is empty, make temp as first node!
            head = temp;
        } else {
            p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }
    
    return head;
}


void displayList(Node* head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
}


int main(int argc, char* argv[]){
    int n = 0;
    Node* HEAD = NULL;    
    printf("\nHow many node: ");
    scanf("%d", &n);
    HEAD = createLinkedList(n);
    displayList(HEAD);

    return 0;
}
