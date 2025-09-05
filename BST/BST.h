//
// Created by Avi Patel on 9/4/25.
//

#pragma once

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val);
    Node* remove(Node* node, int val);
    bool search(Node* node, int val);
    void inorder(Node* node);
    void clear(Node* node); // destructor helper

public:
    BST();
    ~BST();

    void insert(int val);
    void remove(int val);
    bool search(int val);
    void inorderTraversal();
};


