// You are using GCC
#include <iostream>
using namespace std;

class Node {
public:
    int membershipNumber;
    Node* next;

    Node(int membershipNumber) : membershipNumber(membershipNumber), next(nullptr) {}
};

Node* createNode(int membershipNumber) {
    return new Node(membershipNumber);
}

void isMemberInList(Node* head, int membershipToCheck) {
    // Type your code here
    bool found=false;
    Node* temp=head;
    
    while(temp!=nullptr){
        if(temp->membershipNumber==membershipToCheck){
            cout<<"Membership number "<<membershipToCheck<<" is active";
            
            found=true;
            return;
            
        }
        temp=temp->next;
        
    }
    
    if(found==false){
        cout<<"Membership number "<<membershipToCheck<<" is not in the list";
    }
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; i++) {
        int membershipNumber;
        cin >> membershipNumber;
        Node* newNode = createNode(membershipNumber);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int membershipToCheck;
    cin >> membershipToCheck;

    // Type your code here
    isMemberInList(head,membershipToCheck);
    return 0;
}
