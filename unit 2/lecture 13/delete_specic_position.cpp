#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete a node from the doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    // If the node to be deleted is the head
    if (*head_ref == del)
        *head_ref = del->next;

    // If the node to be deleted is not the last node
    if (del->next != NULL)
        del->next->prev = del->prev;

    // If the node to be deleted is not the first node
    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del); // Free the memory occupied by del
}

// Function to delete a node at a given position
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    if (*head_ref == NULL || n <= 0)
        return;

    struct Node* current = *head_ref;

    // Traverse the list to find the node at position n
    for (int i = 1; current != NULL && i < n; i++) {
        current = current->next;
    }

    // If position is greater than the number of nodes
    if (current == NULL)
        return;

    // Delete the node at position n
    deleteNode(head_ref, current);
}

// Function to push a new node at the beginning of the list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
        (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
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
    struct Node* head = NULL;

    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        push(&head, data);
    }

    cout << "Before deletion: ";
    printList(head);

    int pos;
    cin >> pos;

    deleteNodeAtGivenPos(&head, pos);

    cout << "\nAfter deletion: ";
    printList(head);

    return 0;
}
