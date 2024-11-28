#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

typedef Node* NODE;

NODE getnode() {
    NODE x = new Node();
    return x;
}

// Function to insert an item at the front of the circular linked list
NODE insertAtFront(NODE head, int item) {
    NODE temp = getnode();
    temp->data = item;

    if (head == nullptr || head->link == head) {  // Empty or single node
        head->link = temp;
        temp->link = head;
    } else {
        temp->link = head->link;
        head->link = temp;
    }

    head->data++;  // Increment node count stored in header
    return head;
}

// Function to insert an item at the end of the circular linked list
NODE insertAtEnd(NODE head, int item) {
    NODE temp = getnode();
    temp->data = item;

    if (head == nullptr || head->link == head) {  // Empty list or single node
        head->link = temp;
        temp->link = head;
    } else {
        NODE last = head->link;
        // Traverse to the last node (which links to the head)
        while (last->link != head) {
            last = last->link;
        }
        last->link = temp;
        temp->link = head;  // Link new node to the head
    }

    head->data++;  // Increment node count stored in header
    return head;
}

// Function to display the circular linked list
void display(NODE head) {
    if (head == nullptr || head->link == head) {
        cout << "List is empty." << endl;
        return;
    }

    NODE temp = head->link;  // Start after the header node
    do {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != head);  // Loop until we reach the header node again

    cout << endl;
}

int main() {
    NODE head = nullptr;
    int item, n;

    head = getnode();
    head->data = 0;        // Header node contains node count
    head->link = head;     // Circular link to itself (empty list)

    // Insert at the front
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> item;
        head = insertAtFront(head, item);
    }

    // Insert at the end
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> item;
        head = insertAtEnd(head, item);
    }
    cout<<"Number of nodes in the CLL is "<<n+n1<<endl;

    display(head);

    return 0;
}
