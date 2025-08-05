//
// Created by mE on 05/08/2025.
//

#include <iostream>
#include "BST.h"

#include <iomanip>

using namespace std;

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right): data(data), left(left), right(right) {}

BST::BST(): root(nullptr) {}

TreeNode* BST::insert(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value < node -> data) node->left = insert(node->left, value); // value smaller than node
    else node->right = insert(node->right, value);
    return node;
}

TreeNode* BST::findMin(TreeNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

TreeNode *BST::deleteNode(TreeNode *node, int value) {
    if (!node) return nullptr;

    // Value is smaller than root
    if (value < node->data) { // so go left
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        // Value is greater than root so we go right
        node->right = deleteNode(node->right, value);
    } else {
        // Node found
        if (!node->left && !node->right) {
            // Case 1
            // Leaf Node / No Children
            delete node;
            return nullptr;
        }

        if (!node->left || !node->right) {
            // Case 2
            // Only 1 children
            TreeNode* child = node->left ? node->left : node->right;
            delete node;
            return child;
        }

        // Case 3
        // Two children
        TreeNode* minRight = findMin(node->right);
        node->data = minRight->data;
        node->right = deleteNode(node->right, minRight->data);
    }
    return node;
}


void BST::inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::display_inorder() {
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}

void BST::preorder(TreeNode* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::display_preorder() {
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
}

void BST::postorder(TreeNode* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void BST::display_postorder() {
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}


void BST::insert(int value) {
    root = insert(root, value);
}

void BST::remove(int value) {
    root = deleteNode(root, value);
}
