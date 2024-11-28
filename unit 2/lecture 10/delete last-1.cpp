// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteSecondLastNode(struct Node* &head,int pos) {
    if (head == NULL) {
        return;
    }

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos-1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    Node* nodetodel = temp->next;
    temp->next = temp->next->next;
    delete nodetodel;
    
}

void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int size;

    // Input the size of the linked list
    scanf("%d", &size);

    // Input the elements of the linked list
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&head, value);
    }

    printf("Original Linked List: ");
    displayLinkedList(head);

    // Delete the second last node
    deleteSecondLastNode(head,size-1);

    printf("Updated Linked List: ");
    displayLinkedList(head);

    // Clean up the memory allocated for the linked list
    deleteLinkedList(head);

    return 0;
}