#include <iostream>
using namespace std;

// Node of a doubly linked list
struct Node {
    int data;
    struct Node* prev, *next;
};

// Function to create and return a new node of a doubly linked list
struct Node* getNode(int data)
{
    // Allocate node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Put in the data
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert a new node in a sorted way in a sorted doubly linked list
void sortedInsert(struct Node** head_ref, struct Node* newNode)
{
    struct Node* current;

    // Case 1: If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
    }
    // Case 2: If the new node should be inserted before the head
    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }
    // Case 3: Find the node after which the new node needs to be inserted
    else {
        current = *head_ref;

        // Traverse the list to find the insertion point
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }

        // Insert the new node after 'current'
        newNode->next = current->next;

        // If inserting at the end, update 'next' pointers accordingly
        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }

        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the doubly linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    /* Start with the empty doubly linked list */
    struct Node* head = NULL;

    // Input the number of nodes in the list
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        struct Node* new_node = getNode(data);
        sortedInsert(&head, new_node);
    }

    // Insert the last element separately
    int lastData;
    cin >> lastData;
    struct Node* lastNode = getNode(lastData);
    sortedInsert(&head, lastNode);

    printList(head);

    return 0;
}
