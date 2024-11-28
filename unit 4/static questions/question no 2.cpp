
#include <iostream>
#include <stdlib.h>
using namespace std;

struct tnode {
    int data;
    struct tnode *left, *right;
};

struct tnode* CreateBST(struct tnode *root, int item) {
    if (root == nullptr) {
        root = new tnode();
        root->data = item;
        root->left = root->right = nullptr;
    } else if (item < root->data) {
        root->left = CreateBST(root->left, item);
    } else {
        root->right = CreateBST(root->right, item);
    }
    return root;
}

void Inorder(struct tnode *root) {
    if (root != nullptr) {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Preorder(struct tnode *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct tnode *root) {
    if (root != nullptr) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    struct tnode *root = NULL;
    int choice, item, n, i;
    do {
        cin >> choice;
        switch (choice) {
            case 1:
                root = NULL;
                cin >> n;
                for (i = 1; i <= n; i++) {
                    cin >> item;
                    root = CreateBST(root, item);
                }
                break;
            case 2:
                cout << "Inorder: ";
                Inorder(root);
                cout << "\n";
                break;
            case 3:
                cout << "Preorder: ";
                Preorder(root);
                cout << "\n";
                break;
            case 4:
                cout << "Postorder: ";
                Postorder(root);
                cout << "\n";
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }
    } while (1);
    return 0;
}
