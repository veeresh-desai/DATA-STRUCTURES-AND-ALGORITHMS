// You are using GCC
#include <iostream>
using namespace std;

class Node {
public:
int licensePlate;
Node* next;

Node(int licensePlate) : licensePlate(licensePlate), next(nullptr) {}
};

Node* createNode(int licensePlate) {
return new Node(licensePlate);
}

Node* deleteByPlate(Node* head, int plateToRemove) {
// Type your code here
if(head==nullptr) return head;

if(head->licensePlate==plateToRemove)
{
Node* temp=head;
head=head->next;
delete temp;
return head;
}
Node* current=head;
while(current->next!=nullptr && current->next->licensePlate!=plateToRemove)
{
current=current->next;
}
if(current->next!=nullptr)
{
Node* temp=current->next;
current->next=current->next->next;
delete temp;

}
return head;
}

Node* deleteByPosition(Node* head, int position) {
// Type your code here
if(head==nullptr) return head;
if(position==0)
{
Node* temp=head;
head=head->next;
delete temp;
return head;
}
Node* current=head;
for(int i=0;current!=nullptr && i<position-1;i++)

current=current->next;

if(current==nullptr || current->next=nullptr)

return head;

Node* temp=current->next;
current->next=current->next->next;
delete temp;
return head;

}

void printList(Node* head) {
Node* temp = head;
while (temp != nullptr) {
cout << temp->licensePlate << " ";
temp = temp->next;
}
}
fe
int main() {
int N;
cin >> N;

Node* head = nullptr;
Node* tail = nullptr;

for (int i = 0; i < N; i++) {
int licensePlate;
cin >> licensePlate;
Node* newNode = createNode(licensePlate);
if (head == nullptr) {
head = newNode;
tail = newNode;
} else {
tail->next = newNode;
tail = newNode;
}
}

int plateToRemove, positionToRemove;
cin >> plateToRemove;
cin >> positionToRemove;

head = deleteByPlate(head, plateToRemove);
head = deleteByPosition(head, positionToRemove);

printList(head);

return 0;
}