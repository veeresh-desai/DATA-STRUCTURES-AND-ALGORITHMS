#include <iostream>
struct Node {
int data;
Node* next;
};

Node* insert_beg(Node* start, int num) {
Node* newnode = new Node;
newnode->data = num;

if (start == nullptr) {
newnode->next = newnode;
start = newnode;
} else {
Node* ptr = start;
while (ptr->next != start) {
ptr = ptr->next;
}
newnode->next = start;
ptr->next = newnode;
start = newnode;
}
return start;
}

Node* insert_end(Node* start, int num) {
Node* newnode = new Node;
newnode->data = num;

if (start == nullptr) {
newnode->next = newnode;
start = newnode;
} else {
Node* ptr = start;
while (ptr->next != start) {
ptr = ptr->next;
}
ptr->next = newnode;
newnode->next = start;
}
return start;
}

Node* insert_at_position(Node* start, int num, int pos) {
if (start == nullptr) {
std::cout << "The list is empty. Invalid position." << std::endl;
return start;
}

Node* newnode = new Node;
newnode->data = num;

Node* ptr = start;
for (int i = 1; i < pos - 1; ++i) {
ptr = ptr->next;
if (ptr == start) {
std::cout << "Position out of range." << std::endl;
delete newnode;
return start;
}
}

newnode->next = ptr->next;
ptr->next = newnode;

return start;
}

void print_list(Node* start) {
if (start == nullptr) {
std::cout << "The list is empty." << std::endl;
return;
}

Node* ptr = start;
do {
std::cout << ptr->data << " ";
ptr = ptr->next;
} while (ptr != start);
std::cout << std::endl;
}

int main() {
Node* head = nullptr;
int numNodes;

std::cout << "Enter the number of nodes: ";
std::cin >> numNodes;

for (int i = 0; i < numNodes; ++i) {
int value;
std::cout << "Enter value for node " << (i + 1) << ": ";
std::cin >> value;
head = insert_end(head, value);
}

int begValue;
std::cout << "Enter the value to insert at the beginning: ";
std::cin >> begValue;
head = insert_beg(head, begValue);

int endValue;
std::cout << "Enter the value to insert at the end: ";
std::cin >> endValue;
head = insert_end(head, endValue);

int insertValue, position;
std::cout << "Enter the value to insert: ";
std::cin >> insertValue;
std::cout << "Enter the position at which to insert: ";
std::cin >> position;

if (position > 1) {
head = insert_at_position(head, insertValue, position);
} else {
std::cout << "Invalid position. Use insert_beg() for position 1." << std::endl;
}

std::cout << "Final circular linked list: ";
print_list(head);

return 0;
}