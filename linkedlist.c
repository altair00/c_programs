#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
    int data;
    node_t* next;
};

void insert(node_t** head, int data) {

    node_t* temp = malloc(sizeof(node_t));
    node_t* ptr;

    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        ptr = *head;

        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

}

node_t* arrayToLL(int *arr, int size) {
    node_t* head = NULL;

    for(int i=0; i<size; i++) {
        insert(&head, arr[i]);
    }

    return head;
}

void printList(struct node* head) {
    while(head->next!=NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}


int main() {

    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    node_t* head = NULL;

    head = arrayToLL(arr, size);

    printList(head);

    while(head) {
        void *ptr = head;
        head = head->next;
        free(ptr);
    }

    return 0;
}
