#include <iostream>

class Node {
public:
int data;
Node* next;

Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
Node* start;

public:
CircularLinkedList() : start(nullptr) {}


void insert_end(int num) {
Node* newnode = new Node(num);

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
}


void delete_beg() {
if (start == nullptr) {
std::cout << "The list is empty." << std::endl;
return;
}

if (start->next == start) {
delete start;
start = nullptr;
} else {
Node* ptr = start;
while (ptr->next != start) {
ptr = ptr->next;
}
Node* temp = start;
start = start->next;
ptr->next = start;
delete temp;
}
}


void delete_end() {
if (start == nullptr) {
std::cout << "The list is empty." << std::endl;
return;
}

if (start->next == start) { // Only one node
delete start;
start = nullptr;
} else {
Node* ptr = start;
Node* prev = nullptr;
while (ptr->next != start) {
prev = ptr;
ptr = ptr->next;
}
prev->next = start;
delete ptr;
}
}


void delete_at_position(int pos) {
if (start == nullptr) {
std::cout << "The list is empty." << std::endl;
return;
}

Node* ptr = start;
Node* prev = nullptr;


if (pos == 1) {
delete_beg();
return;
}


for (int i = 1; i < pos; ++i) {
prev = ptr;
ptr = ptr->next;
if (ptr == start) {
std::cout << "Position out of range." << std::endl;
return;
}
}


if (ptr->next == start) {
prev->next = start;
delete ptr;
} else {
prev->next = ptr->next;
delete ptr;
}
}


void print_list() const {
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
};

int main() {
CircularLinkedList cll;

cll.insert_end(10);
cll.insert_end(20);
cll.insert_end(30);
cll.insert_end(40);

std::cout << "Circular linked list before deletions: ";
cll.print_list();

// Deleting nodes
int choice;
std::cout << "Choose deletion operation:" << std::endl;
std::cout << "1. Delete from the beginning" << std::endl;
std::cout << "2. Delete from the end" << std::endl;
std::cout << "3. Delete from a specific position" << std::endl;
std::cin >> choice;

switch (choice) {
case 1:
cll.delete_beg();
break;
case 2:
cll.delete_end();
break;
case 3: {
int position;
std::cout << "Enter position to delete: ";
std::cin >> position;
cll.delete_at_position(position);
break;
}
default:
std::cout << "Invalid choice." << std::endl;
break;
}

std::cout << "Final circular linked list after deletions: ";
cll.print_list();

return 0;
}