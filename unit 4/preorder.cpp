// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int v) {
    Node* temp = new Node();
    temp->data = v;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insertLevelOrder(int arr[], int start, int size) {
    Node* temp = nullptr;

    if (start < size) {
        temp = newNode(arr[start]);

        temp->left = insertLevelOrder(arr, 2 * start + 1, size);
        temp->right = insertLevelOrder(arr, 2 * start + 2, size);
    }
    return temp;
}



void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}



void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}




int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* root = nullptr;
    root = insertLevelOrder(arr, 0, n);

    cout << "Inorder traversal: ";
    preorder(root);
    inorder(root);
    postorder(root);
    


    return 0;
}