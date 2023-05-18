#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* insert(Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int tree_height(Node* root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height+1 ;
        else
            return right_height+1 ;
    }
}
void printCurrentlevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) cout << root->data << " ";
    else if (level > 1) {
        printCurrentlevel(root->left, level - 1);
        printCurrentlevel(root->right, level - 1);
    }
}
void printlevelOrder(Node* root) {
    int height = tree_height(root);
    for (int i = 1; i <= height; i++) {
        printCurrentlevel(root, i);
    }

}
int main() {
    int n;
    cin >> n;
    int x;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
   // postorder(root);
  // cout<<tree_height(root)-1;
    printlevelOrder(root);
    return 0;
}