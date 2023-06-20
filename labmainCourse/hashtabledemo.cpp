#include <iostream>
#include <stdlib.h>

#define M 10

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int initdata) {
    Node* node = new Node;
    node->data = initdata;
    node->next = NULL;
    return node;
}

typedef Node* hashtable[M];

void createHashtable(hashtable& hs) {
    for (int i = 0; i < M; i++) {
        hs[i] = NULL;
    }
}

int Hash(int value) {
    return value % M;
}

void addtail(Node*& list, Node* node) {
    if (list == NULL) {
        list = node;
    }
    else {
        Node* rp = list;
        while (rp->next != NULL) {
            rp = rp->next;
        }
        rp->next = node;
    }
}

void insertNode(hashtable& hs, int key) {
    int i = Hash(key);
    Node* node = createNode(key);
    addtail(hs[i], node);
}

void deletehead(Node*& list) {
    if (list != NULL) {
        Node* rm = list;
        list = list->next;
        delete rm;
    }
}

void deleteafter(Node*& q) {
    Node* rm = q->next;
    if (rm != NULL) {
        q->next = rm->next;
        delete rm;
    }
}

void deleteNode(hashtable& hs, int k) {
    int i = Hash(k);
    Node* rm = hs[i];
    Node* q = rm;
    while (rm != NULL && rm->data != k) {
        q = rm;
        rm = rm->next;
    }
    if (rm == NULL) {
        return;
    }
    else if (rm == hs[i]) {
        deletehead(hs[i]);
    }
    else {
        deleteafter(q);
    }
}

Node* searchNode(hashtable hs, int k) {
    int i = Hash(k);
    Node* p = hs[i];
    while (p != NULL && p->data != k) {
        p = p->next;
    }
    if (p == NULL) {
        return NULL;
    }
    else {
        return p;
    }
}

void traverse(Node* list) {
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

void traverseHashtable(hashtable hs) {
    for (int i = 0; i < M; i++) {
        cout << "Bucket " << i << " : ";
        traverse(hs[i]);
    }
}

void insertValue(hashtable& hs) {
    int value = -1;
    do {
        cin >> value;
        if (value == 0) {
            break;
        }
        insertNode(hs, value);
    } while (value != 0);
}

int main() {
    hashtable newtable;
    createHashtable(newtable);
    insertValue(newtable);
    traverseHashtable(newtable);
    return 0;
}
